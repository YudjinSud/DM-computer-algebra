import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: n1
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Сравнение")
    visible: true

    Text {
        id: desN1
        x: 15
        y: 13
        width: 370
        height: 146
        color: "#d5f476"
        text: qsTr("Сравнение натуральных чисел:
0 - если числа равны,
1 - если второе больше первого,
2 - если первое больше второго")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Сравнить")
        onClicked: {

        }
    }

    TextField {
        id: textField
        x: 15
        y: 188
        width: 181
        height: 25
        placeholderText: qsTr("             Первое число")
    }

    TextField {
        id: textField1
        x: 204
        y: 188
        width: 181
        height: 25
        placeholderText: qsTr("             Второе число")
    }

    TextArea {
        id: textArea
        x: 80
        y: 250
        width: 255
        height: 44
    }
}
