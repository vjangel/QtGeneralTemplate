CONFIG      += c++23
TEMPLATE    = app

CONFIG(debug, debug|release) {
    DESTDIR = build/debug
} else {
    DESTDIR = build/release
}

UI_DIR      = $$DESTDIR/.ui
RCC_DIR     = $$DESTDIR/.rcc
MOC_DIR     = $$DESTDIR/.moc
OBJECTS_DIR = $$DESTDIR/.obj

CONFIG      -= \
    debug_and_release

## Custom rules for deployment.
target.path = /work
INSTALLS += target

unix: {
install_file.files = $$PWD/dependent/
install_file.path = /work
INSTALLS += install_file
}

win32: {
MY_PWD = $$PWD
OUTPUT_PWD = $$OUT_PWD/$$DESTDIR

MY_PWD_WIN = $$replace(MY_PWD, /, \\)
OUTPUT_PWD_WIN = $$replace(OUTPUT_PWD, /, \\)

MY_DB_PWD = $$MY_PWD_WIN\dependent
OUT_DB_PWD = $$OUTPUT_PWD_WIN\dependent\

do = $$system("echo d| xcopy $${MY_DB_PWD} /S /Y /E $${OUT_DB_PWD}")

}