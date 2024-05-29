echo off

echo build mblink.dll X32 ....
SET CGO_ENABLED=1
SET GOOS=windows
SET GOARCH=386

cd ../WebBrowser

go build -tags "release" -ldflags "-s -w -H=windowsgui" -o ../dist/Release/wbrowser.dll -buildmode=c-shared .
