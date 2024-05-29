//go:build !windows

package log

import (
	"fmt"
)

func log(format string, vars ...any) {
	fmt.Printf(format+"\n", vars...)
}
