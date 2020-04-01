import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: f7
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Умножение дробей")
    visible: true

    Text {
        id: desN1
        x: 15
        y: 13
        width: 370
        height: 146
        color: "#d5f476"
        text: qsTr("Умножение дробей")
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
        x: 15
        y: 158
        width: 181
        height: 25
        placeholderText: qsTr("            Первый числитель")
    }

    TextField {
        id: textField1
        x: 15
        y: 189
        width: 181
        height: 25
        placeholderText: qsTr("            Первый знаменатель")
    }
    TextField {
        id: textField2
        x: 202
        y: 158
        width: 181
        height: 25
        placeholderText: qsTr("            Второй числитель")
    }

    TextField {
        id: textField3
        x: 202
        y: 189
        width: 181
        height: 25
        placeholderText: qsTr("            Второй знаменатель")
    }
    TextArea {
        id: textArea
        x: 80
        y: 250
        width: 255
        height: 44
    }
}
