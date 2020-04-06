import QtQuick 2.3
import QtQuick.Controls 1.2
import io.qt.examples.BackendIOWrapper 1.0
ApplicationWindow {
    id: i3
    property int algo : 3
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Умножение на (-1)")
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
        text: qsTr("Умножение целого на (-1)")
        font.pixelSize: 20
    }
    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Мне повезет!")
        onClicked: {
            console.log(algo);
            textArea.text = backend.calculateInteger(backend.input1, backend.input1, 0,  algo)
        }
    }

    TextField {
        id: textField
        x: 15
        y: 188
        width: 181
        height: 25
        placeholderText: qsTr("              Число")

        text: backend.input1
        onTextChanged: backend.input1 = text

    }


    TextArea {
        id: textArea
        x: 80
        y: 250
        width: 255
        height: 44

      //  text : backend.input1 + " " + backend.input2
        readOnly: true

    }
}
