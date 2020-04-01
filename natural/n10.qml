import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: n10
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Первая цифра")
    visible: true

    Text {
        id: desN1
        x: 15
        y: 13
        width: 370
        height: 146
        color: "#d5f476"
        text: qsTr("Вычисление первой цифры
деления большего натурального
на меньшее, домноженное
на 10^k,где k - номер
позиции этой цифры
(номер считается с нуля)")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Вычислить")
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
