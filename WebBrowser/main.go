package main

import "C"

import (
	"wbrowser/log"

	blink "github.com/epkgs/mini-blink"
)

func main() {

}

//export Destroy
func Destroy() {
	app = getApp()
	app.Exit()
	app = nil
}

//export Open
func Open(url *C.char) uintptr {

	goUrl := C.GoString(url)

	view := createView(goUrl)

	return uintptr(view.Hwnd)
}

var app *blink.Blink

func getApp() *blink.Blink {

	if app == nil {

		log.Info("未初始化 app，创建新 app")

		app = blink.NewApp()

		app.IPC.Handle("download", func(url string) error {
			return app.Downloader.Download(url)
		})

		go app.KeepRunning()

	}

	return app

}

func createView(url string) *blink.View {

	app := getApp()

	view := app.CreateWebWindowPopup()

	view.Window.MoveToCenter()

	view.LoadURL(url)

	view.ShowWindow()

	view.ShowDevTools(func(devtools *blink.View) {
		devtools.Window.MoveToCenter()
	})

	return view
}
