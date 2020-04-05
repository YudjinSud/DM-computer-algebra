import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    color: "#00557f"
    title: qsTr("Приложение ДМ")

        Button {
            id: button1
            x: 0
            y: 52
            width: 260
            height: 40
            text: qsTr("Натуральные числа")
            onClicked: {
                        var component = Qt.createComponent("natural.qml")
                var window    = component.createObject("n")
                window.show()
            }
        }

        Button {
            id: button2
            x: 0
            y: 105
            width: 260
            height: 40
            text: qsTr("Целые числа")
            onClicked: {
                        var component = Qt.createComponent("integer.qml")
                var window    = component.createObject("i")
                window.show()
            }
        }

        Button {
            id: button3
            x: 0
            y: 158
            width: 260
            height: 40
            text: qsTr("Дроби")
            onClicked: {
                        var component = Qt.createComponent("fractions.qml")
                var window    = component.createObject("f")
                window.show()
            }
        }

        Button {
            id: button4
            x: 0
            y: 214
            width: 260
            height: 40
            text: qsTr("Многочлены")
            onClicked: {
                        var component = Qt.createComponent("polynoms.qml")
                var window    = component.createObject("p")
                window.show()
            }
        }
    Text {
        id: element
        x: 0
        y: 8
        width: 268
        height: 31
        color: "#ffffff"
        text: qsTr("Список алгоритмов")
        font.family: "Times New Roman"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 17
    }

    Image {
        id: image
        x: 296
        y: 0
        width: 322
        height: 356
        source: "leti_logo_krug-eng_2019.png"
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: image1
        x: 0
        y: 381
        width: 100
        height: 98
        source: "../../../Downloads/photo_2020-04-05_17-15-08.jpg"
        fillMode: Image.PreserveAspectFit
    }

}
