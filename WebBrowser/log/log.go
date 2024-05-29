package log

func Info(format string, vars ...any) {
	log("[EmbedBrowser INFO] "+format, vars...)
}

func Warning(format string, vars ...any) {
	log("[EmbedBrowser WARN] "+format, vars...)
}

func Error(format string, vars ...any) {
	log("[EmbedBrowser ERROR] "+format, vars...)
}
