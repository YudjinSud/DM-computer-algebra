import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: f8
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Деление")
    visible: true

    Text {
        id: desN1
        x: 15
        y: 13
        width: 370
        height: 146
        color: "#d5f476"
        text: qsTr("Деление дробей
(делитель отличен от нуля)")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Разделить")
        onClicked: {

        }
    }
    TextField {
        id: textField
        x: 110
        y: 158
        width: 181
        height: 25
        placeholderText: qsTr("                       Дробь")
    }

    TextArea {
        id: textArea
        x: 80
        y: 250
        width: 255
        height: 44
    }

    TextField {
        id: textField2
        x: 110
        y: 189
        width: 181
        height: 25
        placeholderText: qsTr("                     Делитель")
    }
}
