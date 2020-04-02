import QtQuick 2.3
import QtQuick.Controls 1.2

import io.qt.examples.BackendIOWrapper 1.0


ApplicationWindow {
    id: n11
    property int algo : 11
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Частное")
    visible: true

    BackendIOWrapper {
            id : backend
        }

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
                    textArea.text = backend.calculateNatural(backend.input1, backend.input2, 0, algo)
                }
    }

    TextField {
        id: textField
        x: 15
        y: 188
        width: 181
        height: 25
        placeholderText: qsTr("             Первое число")
        text: backend.input1
                onTextChanged: backend.input1 = text
    }

    TextField {
        id: textField1
        x: 204
        y: 188
        width: 181
        height: 25
        placeholderText: qsTr("             Второе число")
        text : backend.input2
                onTextChanged: backend.input2 = text
    }

    TextArea {
        id: textArea
        x: 80
        y: 250
        width: 255
        height: 44
        readOnly: true
    }
}
