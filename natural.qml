import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    color: "#00557f"
    title: qsTr("Натуральные числа")
    id: n
    width: screen.width / 2
    height: screen.height / 3

    maximumHeight: screen.height / 2
    maximumWidth: screen.width / 3

    minimumHeight: screen.height / 2
    minimumWidth: screen.width / 3


    Button {
        id: n1
        x: 16
        y: 13
        width: 111
        height: 39
        text: qsTr("Сравнение")
        onClicked: {
                    var component = Qt.createComponent("natural/n1.qml")
            var window    = component.createObject("n1")
            window.show()
        }
    }

    Button {
        id: n2
        x: 147
        y: 13
        width: 111
        height: 39
        text: qsTr("Проверка на 0")
        onClicked: {
                    var component = Qt.createComponent("natural/n2.qml")
            var window    = component.createObject("n2")
            window.show()
        }
    }

    Button {
        id: n3
        x: 276
        y: 13
        width: 111
        height: 39
        text: qsTr("+1")
        onClicked: {
                    var component = Qt.createComponent("natural/n3.qml")
            var window    = component.createObject("n3")
            window.show()
        }
    }

    Button {
        id: n4
        x: 16
        y: 58
        width: 111
        height: 39
        text: qsTr("Сложение")
        onClicked: {
                    var component = Qt.createComponent("natural/n4.qml")
            var window    = component.createObject("n4")
            window.show()
        }
    }

    Button {
        id: n5
        x: 147
        y: 58
        width: 111
        height: 39
        text: qsTr("Вычитание")
        onClicked: {
                    var component = Qt.createComponent("natural/n5.qml")
            var window    = component.createObject("n5")
            window.show()
        }
    }

    Button {
        id: n6
        x: 276
        y: 58
        width: 111
        height: 39
        text: qsTr("Умножение на цифру")
        onClicked: {
                    var component = Qt.createComponent("natural/n6.qml")
            var window    = component.createObject("n6")
            window.show()
        }
    }

    Button {
        id: n7
        x: 16
        y: 106
        width: 111
        height: 39
        text: qsTr("Умножение на 10^k")
        onClicked: {
                    var component = Qt.createComponent("natural/n7.qml")
            var window    = component.createObject("n7")
            window.show()
        }
    }

    Button {
        id: n8
        x: 147
        y: 106
        width: 111
        height: 39
        text: qsTr("Умножение")
        onClicked: {
                    var component = Qt.createComponent("natural/n8.qml")
            var window    = component.createObject("n8")
            window.show()
        }
    }

    Button {
        id: n9
        x: 276
        y: 106
        width: 111
        height: 39
        text: qsTr("Вычитание №2")
        onClicked: {
                    var component = Qt.createComponent("natural/n9.qml")
            var window    = component.createObject("n9")
            window.show()
        }
    }

    Button {
        id: n10
        x: 16
        y: 154
        width: 111
        height: 39
        text: qsTr("Деление")
        onClicked: {
                    var component = Qt.createComponent("natural/n10.qml")
            var window    = component.createObject("n10")
            window.show()
        }
    }

    Button {
        id: n11
        x: 147
        y: 154
        width: 111
        height: 39
        text: qsTr("Частное")
        onClicked: {
                    var component = Qt.createComponent("natural/n11.qml")
            var window    = component.createObject("n11")
            window.show()
        }
    }

    Button {
        id: n12
        x: 276
        y: 154
        width: 111
        height: 39
        text: qsTr("Остаток")
        onClicked: {
                    var component = Qt.createComponent("natural/n12.qml")
            var window    = component.createObject("n12")
            window.show()
        }
    }

    Button {
        id: n13
        x: 16
        y: 202
        width: 111
        height: 39
        text: qsTr("НОД")
        onClicked: {
                    var component = Qt.createComponent("natural/n13.qml")
            var window    = component.createObject("n13")
            window.show()
        }
    }

    Button {
        id: n14
        x: 147
        y: 202
        width: 111
        height: 39
        text: qsTr("НОК")
        onClicked: {
                    var component = Qt.createComponent("natural/n14.qml")
            var window    = component.createObject("n14")
            window.show()
        }
    }
}
