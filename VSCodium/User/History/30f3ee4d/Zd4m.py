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

    def exitProgram(self):
        exit()

root = Tk()
app = Window(root)

# set window title
root.wm_title("Desktop Buddy!")

#show window
root.mainloop()