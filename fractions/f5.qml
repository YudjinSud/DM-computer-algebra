import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: f5
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Сложение дробей")
    visible: true

    Text {
        id: desN1
        x: 15
        y: 13
        width: 370
        height: 139
        color: "#d5f476"
        text: qsTr("Сложение дробей")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Сложить")
        onClicked: {

        }
    }

    TextField {
        id: textField1
        x: 15
        y: 189
        width: 181
        height: 25
    }

    TextField {
        id: textField3
        x: 202
        y: 189
        width: 181
        height: 25
    }

    TextArea {
        id: textArea
        x: 80
        y: 250
        width: 255
        height: 44
    }
}
