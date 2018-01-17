INCLUDEPATH += $$PWD/

CONFIG(debug, debug|release){
    LIBS+= -L$$PWD/../../../Build/bin -lGuid
}else{
    LIBS+= -L$$PWD/../../../Build/bin -lGui
}
