import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: i
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Целые числа")

    Button {
        id: i1
        x: 16
        y: 13
        width: 111
        height: 39
        text: qsTr("Абсолютная величина")
        onClicked: {
                    var component = Qt.createComponent("integer/i1.qml")
            var window    = component.createObject("i1")
            window.show()
        }
    }

    Button {
        id: i2
        x: 147
        y: 13
        width: 111
        height: 39
        text: qsTr("Проверка знака")
        onClicked: {
                    var component = Qt.createComponent("integer/i2.qml")
            var window    = component.createObject("i2")
            window.show()
        }
    }

    Button {
        id: i3
        x: 276
        y: 13
        width: 111
        height: 39
        text: qsTr("Умножение на (-1)")
        onClicked: {
                    var component = Qt.createComponent("integer/i3.qml")
            var window    = component.createObject("i3")
            window.show()
        }
    }

    Button {
        id: i4
        x: 16
        y: 58
        width: 111
        height: 39
        text: qsTr("Натуральное в целое")
        onClicked: {
                    var component = Qt.createComponent("integer/i4.qml")
            var window    = component.createObject("i4")
            window.show()
        }
    }

    Button {
        id: i5
        x: 147
        y: 58
        width: 111
        height: 39
        text: qsTr("Неотрицательное
в натуральное")
        onClicked: {
                    var component = Qt.createComponent("integer/i5.qml")
            var window    = component.createObject("i5")
            window.show()
        }
    }

    Button {
        id: i6
        x: 276
        y: 58
        width: 111
        height: 39
        text: qsTr("Сложение")
        onClicked: {
                    var component = Qt.createComponent("integer/i6.qml")
            var window    = component.createObject("i6")
            window.show()
        }
    }

    Button {
        id: i7
        x: 16
        y: 107
        width: 111
        height: 39
        text: qsTr("Вычитание")
        onClicked: {
                    var component = Qt.createComponent("integer/i7.qml")
            var window    = component.createObject("i7")
            window.show()
        }
    }

    Button {
        id: i8
        x: 147
        y: 107
        width: 111
        height: 39
        text: qsTr("Умножение")
        onClicked: {
                    var component = Qt.createComponent("integer/i8.qml")
            var window    = component.createObject("i8")
            window.show()
        }
    }

    Button {
        id: i9
        x: 276
        y: 107
        width: 111
        height: 39
        text: qsTr("Частное")
        onClicked: {
                    var component = Qt.createComponent("integer/i9.qml")
            var window    = component.createObject("i9")
            window.show()
        }
    }

    Button {
        id: i10
        x: 16
        y: 155
        width: 111
        height: 39
        text: qsTr("Остаток")
        onClicked: {
                    var component = Qt.createComponent("integer/i10.qml")
            var window    = component.createObject("i10")
            window.show()
        }
    }

    Text {
        id: element
        x: 16
        y: 219
        width: 371
        height: 159
        color: "#d5f476"
        text: qsTr("Ввод целых чисел
осуществляется так же, как и всегда.
Отличного дня!)")
        font.pixelSize: 20
    }
}
