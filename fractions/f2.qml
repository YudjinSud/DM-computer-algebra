import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: f2
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Проверка")
    visible: true

    Text {
        id: desN1
        x: 15
        y: 13
        width: 370
        height: 146
        color: "#d5f476"
        text: qsTr("Проверка на целое.
Если рациональное число является
целым - «да», иначе «нет»")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Проверить")
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
        x: 80
        y: 250
        width: 255
        height: 44
    }
}
