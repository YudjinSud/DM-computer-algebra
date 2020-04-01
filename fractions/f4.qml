import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: f4
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Преобразование")
    visible: true

    Text {
        id: desN1
        x: 15
        y: 13
        width: 370
        height: 146
        color: "#d5f476"
        text: qsTr("Преобразование дробного в целое
(если знаменатель равен 1)")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 157
        y: 219
        text: qsTr("Преобразовать")
        onClicked: {

        }
    }

    TextField {
        id: textField
        x: 110
        y: 188
        width: 181
        height: 25
    }

    TextArea {
        id: textArea
        x: 73
        y: 250
        width: 255
        height: 44
    }
}
