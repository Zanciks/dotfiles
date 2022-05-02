from tkinter import * 
root = Tk()

class Window(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.master = master

app = Window(root)

# set window title
room.wm_title("Desktop Buddy!")

#show window
root.mainloop()