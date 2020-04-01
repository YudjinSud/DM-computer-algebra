import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: n11
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Частное")
    visible: true

    Text {
        id: desN1
        x: 15
        y: 13
        width: 370
        height: 146
        color: "#d5f476"
        text: qsTr("Частное от деления большего
натурального числа
на меньшее или равное
натуральное с остатком
(делитель отличен от нуля)")
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
