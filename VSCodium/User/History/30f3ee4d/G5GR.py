from tkinter import * 
root = Tk()
app = Window(root)

class Window(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.master = master

# set window title
room.wm_title("Desktop Buddy!")

#show window
root.mainloop()