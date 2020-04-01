import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: i3
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Умножение на (-1)")
    visible: true

    Text {
        id: desN1
        x: 15
        y: 13
        width: 370
        height: 146
        color: "#d5f476"
        text: qsTr("Умножение целого на (-1)")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Умножить")
        onClicked: {

        }
    }
    TextField {
        id: textField
        x: 110
        y: 188
        width: 181
        height: 25
        readOnly: true
        placeholderText: qsTr("               Введите число")
    }
    TextArea {
        id: textArea
        x: 80
        y: 250
        width: 255
        height: 44
    }
}
