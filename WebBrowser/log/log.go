package log

func Info(format string, vars ...any) {
	log("[WBrowser INFO] "+format, vars...)
}

func Warning(format string, vars ...any) {
	log("[WBrowser WARN] "+format, vars...)
}

func Error(format string, vars ...any) {
	log("[WBrowser ERROR] "+format, vars...)
}
