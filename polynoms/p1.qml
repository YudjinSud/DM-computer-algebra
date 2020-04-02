import QtQuick 2.3
import QtQuick.Controls 1.2

import io.qt.examples.BackendIOWrapper 1.0

ApplicationWindow {
    id: p1
    property int algo : 1
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Сложение многочленов")
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
        text: qsTr("Сложение многочленов")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Сложить")
        onClicked: {
            console.log(algo);
            textArea.text = backend.calculatePoly(backend.input1, backend.input2, 0, "(1)/(1)",  algo)
        }
    }

    TextField {
        id: textField
        x: 15
        y: 188
        width: 181
        height: 25
        placeholderText: qsTr("           Первый полином")
        text: backend.input1
        onTextChanged: backend.input1 = text

    }

    TextField {
        id: textField1
        x: 204
        y: 188
        width: 181
        height: 25
        placeholderText: qsTr("           Второй полином")
        text: backend.input2
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
