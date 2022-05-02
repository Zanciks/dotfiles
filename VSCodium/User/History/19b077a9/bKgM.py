from tkinter import * 

root = Tk()

def exitProgram():
    exit()

def Talk():
    exit()

buddyMenu = Menu(root, tearoff = False)
buddyMenu.add_command(label = "Talk")
buddyMenu.add_command(label = "Exit", command = exitProgram)

def popupMenu(event):
    buddyMenu.tk_popup(event.x_root, event.y_root)

root.bind("<Button-3>", popupMenu)

background_image = PhotoImage(file = "output-onlinepngtools.png")
label1 = Label(root, image = background_image)
label1.place(x = 0, y = 0)

root.geometry("144x468")
root.wait_visibility(root)
root.wm_attributes('-alpha', 0)
root.mainloop()