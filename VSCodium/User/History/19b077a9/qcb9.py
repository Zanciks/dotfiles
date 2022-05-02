from tkinter import * 

root = Tk()

buddyMenu = Menu(root, tearoff = False)
buddyMenu.add_command(label = "Talk")
buddyMenu.add_command(label = "Exit", command = exitProgram)

def exitProgram(self):
    exit()

background_image = PhotoImage(file = "output-onlinepngtools.png")
label1 = Label(root, image = background_image)
label1.place(x = 0, y = 0)

root.geometry("144x468")
root.wm_attributes('-alpha', 0.5)
root.mainloop()