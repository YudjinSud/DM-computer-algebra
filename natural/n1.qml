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
        text: qsTr("Тут нужно вставить описание алгоритма с сайта Позднякова")
        font.pixelSize: 12
    }

    TextInput {
        id: textInput
        x: 15
        y: 190
        width: 187
        height: 20
        text: qsTr("Text Input")
        inputMask: "Первое число"
        wrapMode: Text.WordWrap
        font.pixelSize: 12
    }

    TextInput {
        id: textInput1
        x: 202
        y: 190
        width: 183
        height: 20
        text: qsTr("Text Input")
        inputMask: "Второе число"
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 171
        y: 216
        text: qsTr("Сравнить")
        onClicked: {

        }
    }

    TextEdit {
        id: textEdit
        x: 160
        y: 259
        width: 80
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }
}
