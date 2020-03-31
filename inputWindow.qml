import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: root
    width: 400; height: 400

    Text {
        anchors.centerIn: parent
        text: qsTr("Hello World.")
    }
}
