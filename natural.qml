import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    color: "#00557f"
    title: qsTr("Натуральные числа")
    id: n
    width: 400; height: 400

    Button {
        id: n1
        x: 16
        y: 13
        width: 111
        height: 39
        text: qsTr("Сравнение")
        onClicked: {
                    var component = Qt.createComponent("C:\Users\User\source\repos\DM-computer-algebra/natural/n1.qml")
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
    }

    Button {
        id: n3
        x: 276
        y: 13
        width: 111
        height: 39
        text: qsTr("+1")
    }

    Button {
        id: n4
        x: 16
        y: 58
        width: 111
        height: 39
        text: qsTr("Сложение")
    }

    Button {
        id: n5
        x: 147
        y: 58
        width: 111
        height: 39
        text: qsTr("Вычитание")
    }

    Button {
        id: n6
        x: 276
        y: 58
        width: 111
        height: 39
        text: qsTr("Умножение на цифру")
    }

    Button {
        id: n7
        x: 16
        y: 106
        width: 111
        height: 39
        text: qsTr("Умножение на 10^k")
    }

    Button {
        id: n8
        x: 147
        y: 106
        width: 111
        height: 39
        text: qsTr("Умножение")
    }

    Button {
        id: n9
        x: 276
        y: 106
        width: 111
        height: 39
        text: qsTr("Вычитание №2")
    }

    Button {
        id: n10
        x: 16
        y: 154
        width: 111
        height: 39
        text: qsTr("Деление")
    }

    Button {
        id: n11
        x: 147
        y: 154
        width: 111
        height: 39
        text: qsTr("Частное")
    }

    Button {
        id: n12
        x: 276
        y: 154
        width: 111
        height: 39
        text: qsTr("Остаток")
    }

    Button {
        id: n13
        x: 16
        y: 202
        width: 111
        height: 39
        text: qsTr("НОД")
    }

    Button {
        id: n14
        x: 147
        y: 202
        width: 111
        height: 39
        text: qsTr("НОК")
    }
}
