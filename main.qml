import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    color: "#00557f"
    title: qsTr("Приложение ДМ")

    ListView {
        id: listView
        y: 40
        width: 230
        height: 427
        anchors.leftMargin: 0
        anchors.rightMargin: 372
        anchors.topMargin: 46
        topMargin: 0
        contentWidth: 0
        spacing: 3
        layoutDirection: Qt.LeftToRight
        orientation: ListView.Vertical
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.left: parent.left
        clip: false
        opacity: 0.557
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                spacing: 10
                Button {
                    width: (applicationWindow.width/640)*258
                    height: applicationWindow.height/12
                    Text {
                        text: name
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }
                }
            }
        }

        Button {
            id: button
            width: 260
            height: 40
            text: qsTr("N-1")

            onClicked: {
                        var component = Qt.createComponent("inputWindow.qml")
                var window    = component.createObject("root")
                window.show()
            }
        }

        Button {
            id: button1
            x: 0
            y: 52
            width: 260
            height: 40
            text: qsTr("N-1")
        }

        Button {
            id: button2
            x: 0
            y: 105
            width: 260
            height: 40
            text: qsTr("N-1")
        }

        Button {
            id: button3
            x: 0
            y: 158
            width: 260
            height: 40
            text: qsTr("N-1")
        }

        Button {
            id: button4
            x: 0
            y: 214
            width: 260
            height: 40
            text: qsTr("N-1")
        }

        Button {
            id: button5
            x: 0
            y: 272
            width: 260
            height: 40
            text: qsTr("N-1")
        }

        Button {
            id: button6
            x: 0
            y: 326
            width: 260
            height: 40
            text: qsTr("N-1")
        }

        Button {
            id: button7
            x: 0
            y: 379
            width: 260
            height: 40
            text: qsTr("N-1")
        }
    }

    Text {
        id: element
        x: 0
        y: 9
        width: 268
        height: 31
        color: "#ffffff"
        text: qsTr("Список алгоритмов")
        font.family: "Times New Roman"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 17
    }

    Image {
        id: image
        x: 296
        y: 46
        width: 322
        height: 410
        source: "leti_logo_krug-eng_2019.png"
        fillMode: Image.PreserveAspectFit
    }

}


