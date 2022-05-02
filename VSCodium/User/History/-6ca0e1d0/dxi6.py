import tkinter as tk
root = tk.Tk()
root.overrideredirect(True)
root.wait_visibility(root)
root.wm_attributes("-alpha", 0.5)
root.mainloop()