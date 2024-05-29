echo off

echo build mblink.dll X64 ....
SET CGO_ENABLED=1
SET GOOS=windows
SET GOARCH=amd64

cd ../WebBrowser

go build -tags "release" -ldflags "-s -w -H=windowsgui" -o ../dist/Release_x64/wbrowser.dll -buildmode=c-shared .


echo build libenergy.dll X64 ....

cd ../WEnergy

go build -tags "release" -ldflags "-s -w -H=windowsgui" -o ../dist/Release_x64/libenergy.dll -buildmode=c-shared .
