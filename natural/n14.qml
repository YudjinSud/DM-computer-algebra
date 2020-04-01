import QtQuick 2.3
import QtQuick.Controls 1.2

import io.qt.examples.NaturalBackendWrapper 1.0

ApplicationWindow {
    id: n14
    property int algo : 14
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("НОК")
    visible: true


    NaturalBackendWrapper {
            id : backend
        }

    Text {
        id: desN1
        x: 15
        y: 13
        width: 370
        height: 146
        color: "#d5f476"
        text: qsTr("НОК натуральных чисел")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Вычислить")
        onClicked: {
            textArea.text = backend.calculate(backend.input1, backend.input2, algo)
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
        text: backend.input1
               onTextChanged: backend.input1 = text

    }

    TextArea {
        id: textArea
        x: 80
        y: 250
        width: 255
        height: 44
        text : backend.input2
                onTextChanged: backend.input2 = text
    }
}
