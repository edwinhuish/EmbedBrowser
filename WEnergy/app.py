import tkinter as tk
from ctypes import cdll, wintypes
import os
import multiprocessing

def load_dll_and_init():
    current_directory = os.getcwd()
    libenergyPath = os.path.join(current_directory, "libenergy.dll")
    libenergy = cdll.LoadLibrary(libenergyPath)
    initCEFApplication = libenergy.initCEFApplication
    initCEFApplication()

def show_window_from_dll():
    current_directory = os.getcwd()
    libenergyPath = os.path.join(current_directory, "libenergy.dll")
    libenergy = cdll.LoadLibrary(libenergyPath)
    cefFormShow = libenergy.cefFormShow
    cefFormShow()

def main():
    root = tk.Tk()
    root.title("python-load-dll")
    root.geometry("400x300")

    def load_dll_function():
        print('call_dll_function in a new process')
        p = multiprocessing.Process(target=load_dll_and_init)
        p.start()
        p.join()

    def show_window_function():
        print('show_window_function in a new process')
        p = multiprocessing.Process(target=show_window_from_dll)
        p.start()
        p.join()

    loadLibenergyBtn = tk.Button(root, text="加载libenergy.dll", command=load_dll_function)
    loadLibenergyBtn.pack()

    showWindowBtn = tk.Button(root, text="显示libenergy创建的窗口", command=show_window_function)
    showWindowBtn.pack()

    # 进入主事件循环
    root.mainloop()

if __name__ == "__main__":
    main()
