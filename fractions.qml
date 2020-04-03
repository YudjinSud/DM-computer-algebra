import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: f
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Дроби")

    Button {
        id: q1
        x: 16
        y: 13
        width: 111
        height: 39
        text: qsTr("Сокращение")
        onClicked: {
                    var component = Qt.createComponent("fractions/f1.qml")
            var window    = component.createObject("f1")
            window.show()
        }
    }

    Button {
        id: q2
        x: 147
        y: 13
        width: 111
        height: 39
        text: qsTr("Проверка на целое")
        onClicked: {
                    var component = Qt.createComponent("fractions/f2.qml")
            var window    = component.createObject("f2")
            window.show()
        }
    }

    Button {
        id: q3
        x: 276
        y: 13
        width: 111
        height: 39
        text: qsTr("Целое в дробное")
        onClicked: {
                    var component = Qt.createComponent("fractions/f3.qml")
            var window    = component.createObject("f3")
            window.show()
        }
    }

    Button {
        id: q4
        x: 16
        y: 58
        width: 111
        height: 39
        text: qsTr("Дробное в целое")
        onClicked: {
                    var component = Qt.createComponent("fractions/f4.qml")
            var window    = component.createObject("f4")
            window.show()
        }
    }

    Button {
        id: q5
        x: 147
        y: 58
        width: 111
        height: 39
        text: qsTr("Сложение")
        onClicked: {
                    var component = Qt.createComponent("fractions/f5.qml")
            var window    = component.createObject("f5")
            window.show()
        }
    }

    Button {
        id: q6
        x: 276
        y: 58
        width: 111
        height: 39
        text: qsTr("Вычитание")
        onClicked: {
                    var component = Qt.createComponent("fractions/f6.qml")
            var window    = component.createObject("f6")
            window.show()
        }
    }

    Button {
        id: q7
        x: 16
        y: 106
        width: 111
        height: 39
        text: qsTr("Умножение")
        onClicked: {
                    var component = Qt.createComponent("fractions/f7.qml")
            var window    = component.createObject("f7")
            window.show()
        }
    }

    Button {
        id: q8
        x: 147
        y: 106
        width: 111
        height: 39
        text: qsTr("Деление")
        onClicked: {
                    var component = Qt.createComponent("fractions/f8.qml")
            var window    = component.createObject("f8")
            window.show()
        }
    }

    Text {
        id: element
        x: 16
        y: 180
        color: "#d5f476"
        width: 371
        height: 207
        text: qsTr("Как вводить дроби:
Дробь вводится в виде
   (числитель)/(знаменатель)
Например, вводить 1/2 нужно как
    (1)/(2)")
        font.pixelSize: 20
    }
}
