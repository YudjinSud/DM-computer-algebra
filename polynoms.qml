import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: p
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Многочлены")

    Button {
        id: p1
        x: 16
        y: 13
        width: 111
        height: 39
        text: qsTr("Сложение")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p1.qml")
            var window    = component.createObject("p1")
            window.show()
        }
    }

    Button {
        id: p2
        x: 147
        y: 13
        width: 111
        height: 39
        text: qsTr("Вычитание")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p2.qml")
            var window    = component.createObject("p2")
            window.show()
        }
    }

    Button {
        id: p3
        x: 276
        y: 13
        width: 111
        height: 39
        text: qsTr("Умножение на число")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p3.qml")
            var window    = component.createObject("p3")
            window.show()
        }
    }

    Button {
        id: p4
        x: 16
        y: 58
        width: 111
        height: 39
        text: qsTr("Умножение на x^k")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p4.qml")
            var window    = component.createObject("p4")
            window.show()
        }
    }

    Button {
        id: p5
        x: 147
        y: 58
        width: 111
        height: 39
        text: qsTr("Старший
коэффициент")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p5.qml")
            var window    = component.createObject("p5")
            window.show()
        }
    }

    Button {
        id: p6
        x: 276
        y: 58
        width: 111
        height: 39
        text: qsTr("Степень")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p6.qml")
            var window    = component.createObject("p6")
            window.show()
        }
    }

    Button {
        id: p7
        x: 16
        y: 106
        width: 111
        height: 39
        text: qsTr("Вынесение НОК")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p7.qml")
            var window    = component.createObject("p7")
            window.show()
        }
    }

    Button {
        id: p8
        x: 147
        y: 106
        width: 111
        height: 39
        text: qsTr("Умножение")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p8.qml")
            var window    = component.createObject("p8")
            window.show()
        }
    }

    Button {
        id: p9
        x: 276
        y: 106
        width: 111
        height: 39
        text: qsTr("Частное")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p9.qml")
            var window    = component.createObject("p9")
            window.show()
        }
    }

    Button {
        id: p10
        x: 16
        y: 154
        width: 111
        height: 39
        text: qsTr("Остаток")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p10.qml")
            var window    = component.createObject("p10")
            window.show()
        }
    }

    Button {
        id: p11
        x: 147
        y: 154
        width: 111
        height: 39
        text: qsTr("НОД")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p11.qml")
            var window    = component.createObject("p11")
            window.show()
        }
    }

    Button {
        id: p12
        x: 276
        y: 154
        width: 111
        height: 39
        text: qsTr("Производная")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p12.qml")
            var window    = component.createObject("p12")
            window.show()
        }
    }

    Button {
        id: p13
        x: 16
        y: 202
        width: 111
        height: 39
        text: qsTr("Преобразование")
        onClicked: {
                    var component = Qt.createComponent("polynoms/p13.qml")
            var window    = component.createObject("p13")
            window.show()
        }
    }

    Text {
        id: element
        x: 16
        y: 258
        width: 371
        height: 127
        color: "#d5f476"
        text: qsTr("Ввод полиномов.
Коэффициенты перед одночленами - дроби.
Как вводить дроби:
   (числитель)/(знаменатель)
После коэффициента без пробела вводится буква,
знак "^" и показатель степени.
Далее знак "+" (или "-") и (без пробела) следующий одночлен.
Пример: (1)/(2)x^2+(1)/(3)x^1+(1)/(4)")
        font.pixelSize: 12
    }
}
