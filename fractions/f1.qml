import QtQuick 2.3
import QtQuick.Controls 1.2

import io.qt.examples.BackendIOWrapper 1.0

ApplicationWindow {
    id: f1
    property int algo : 1
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Сокращение дроби")
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
        text: qsTr("Сокращение дроби")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Мне повезет!")
        onClicked: {
            console.log(algo);
            backend.input2 = "(1)/(1)";
            textArea.text = backend.calculateFraction(backend.input1, backend.input1, 0,  algo)
        }
    }

    TextField {
        id: textField
        x: 15
        y: 188
        width: 181
        height: 25
        placeholderText: qsTr("              Дробь")

        text: backend.input1
        onTextChanged: backend.input1 = text

    }

    TextArea {
        id: textArea
        x: 73
        y: 248
        width: 255
        height: 44
        readOnly: true
    }
}
