import QtQuick 2.3
import QtQuick.Controls 1.2

import io.qt.examples.BackendIOWrapper 1.0

ApplicationWindow {
    id: n9
    property int algo : 9
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Вычитание из натурального другого натурального")
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
        text: qsTr("Вычитание из натурального другого
натурального, умноженного на
цифру для случая
с неотрицательным результатом")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Вычесть")
        onClicked: {
                    textArea.text = backend.calculateNatural(backend.input1, backend.input2, backend.input3, algo)
                }
    }

    TextField {
        id: textField
        x: 15
        y: 188
        width: 89
        height: 25
        placeholderText: qsTr("             Первое число")
        text: backend.input1
                onTextChanged: backend.input1 = text
    }

    TextField {
        id: textField1
        x: 148
        y: 188
        width: 98
        height: 25
        text: backend.input2
        placeholderText: qsTr("             Второе число")
                onTextChanged: backend.input2 = text
    }

    TextField {
        id: textField2
        x: 284
        y: 188
        width: 86
        height: 25
        placeholderText: qsTr("             Цифра")
        text : backend.input3
                onTextChanged: backend.input3 = text
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
