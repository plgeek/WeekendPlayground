import time
import adafruit_trellism4
from tinytext import TinyText
tt = TinyText()
colors = [
(0,0,0),
(255,0,0),
(0,255,0),
(0,0,255),
(0,255,255),
(255,0,255),
(255,255,0),
(255,255,255)]
black = colors[0]
green = colors[2]
red = colors[1]
white = colors[7]
trellis = adafruit_trellism4.TrellisM4Express()
trellis.pixels.auto_write = False

def show_cols(cols,offset=0,fg=white,bg=black):
    coln = len(cols)
    for i in  range(0,8):
        for j in  range(0,4):
            b = cols[(i+offset) % coln][j]
            trellis.pixels[i,j] = fg if b else bg
    trellis.pixels.show()

def scroll_string(s,delay=0.25,fg=white,bg=black):
    str_cols =  list(tt.get_string_colums(s))
    for i in range(0,len(str_cols)):
        show_cols(str_cols,offset=i,fg=fg,bg=bg)
        time.sleep(delay)

def demo():
  scroll_string(" HELLO WORLD!",fg=red,delay=0.08)
  scroll_string(" HELLO WORLD!",fg=green,delay=0.08)
  text="1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ !@#$%^&*()-=_+[]\\{}|;':\",./<>?"
  n = 0
  for t in text:
    scroll_string("  "+t,fg=colors[(n%7)+1],delay=0.08)
    n+=1

def wait_for_key(delay=0.1,n=10,dflt=(0,0)):
    for i in range(0,n):
        keys = trellis.pressed_keys
        if(keys):
            return keys[0]
        time.sleep(delay)
    return dflt

def demo2():
    text="1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ !@#$%^&*()-=_+[]\\{}|;':\",./<>?"
    for t in text:
        r,c = wait_for_key()
        scroll_string("  "+t,
            fg=colors[(r%7)+1],
            delay=0.5/(c+1))

def fill_cell_rainbow(delay=0.25):
  for off in range(0,32):
    for i in range(0,8):
      for j in range(0,4):
        trellis.pixels[i,j] = colors[(off + i + j) % 8] 
    trellis.pixels.show()
    time.sleep(delay)  

def run_demos(n,demo_num):
  for i in range(0,n+1):
    if demo_num == 0:
      fill_cell_rainbow()
    elif demo_num == 1:
      demo()
    elif demo_num == 2:
      demo2()
    elif demo_num == 3:
      scroll_string(" QUYNH IS NUMBER 1",fg=red)

while True:
    loop, demo_num = wait_for_key()
    run_demos(loop, demo_num)
    