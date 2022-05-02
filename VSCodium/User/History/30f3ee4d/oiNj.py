from tkinter import * 

class Window(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.master = master

        menu = Menu(self.master)
        self.master.config(menu=menu)

        buddyMenu = Menu(menu)
        buddyMenu.add_command(label="Talk")
        buddyMenu.add_command(label="Exit", command = self.exitProgram)
        # buddyMenu.separator()

    def exitProgram(self):
        exit()

root = Tk()
app = Window(root)

def my_popup(event):
    Window.buddyMenu.tk_popup(event.x_root, event.y_root)

# bind right click to menu
root.bind("<Button-3>", my_popup)

# set window title
root.wm_title("Desktop Buddy!")

# show window
root.mainloop()