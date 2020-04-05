import QtQuick 2.12
import QtQuick.Controls 2.5

import QtQuick.Window 2.0

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: screen.width / 2
    height: screen.height / 3

    maximumHeight: screen.height / 2
    maximumWidth: screen.width / 3

    minimumHeight: screen.height / 2
    minimumWidth: screen.width / 3

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

}
