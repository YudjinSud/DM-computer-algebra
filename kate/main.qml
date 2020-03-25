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
        model: ListModel {
            ListElement {
                name: "   N-1. COM_NN_D"
            }

            ListElement {
                name: "   N-2. NZER_N_B"
            }

            ListElement {
                name: "   N-3. ADD_1N_N"
            }

            ListElement {
                name: "   N-4. ADD_NN_N"
            }
            ListElement {
                name: "   N-5. SUB_NN_N"
            }

            ListElement {
                name: "   N-6. MUL_ND_N"
            }

            ListElement {
                name: "   N-7. MUL_Nk_N"
            }

            ListElement {
                name: "   N-8. MUL_NN_N"
            }
            ListElement {
                name: "   N-9. SUB_NDN_N"
            }

            ListElement {
                name: "   N-10. DIV_NN_Dk"
            }

            ListElement {
                name: "   N-11. DIV_NN_N"
            }

            ListElement {
                name: "   N-12. MOD_NN_N"
            }
            ListElement {
                name: "   N-13. GCF_NN_N"
            }

            ListElement {
                name: "   N-14. LCM_NN_N"
            }

            ListElement {
                name: "   Z-1. ABS_Z_N"
            }

            ListElement {
                name: "   Z-2. POZ_Z_D"
            }
            ListElement {
                name: "   Z-3. MUL_ZM_Z"
            }

            ListElement {
                name: "   Z-4. TRANS_N_Z"
            }

            ListElement {
                name: "   Z-5. TRANS_Z_N"
            }

            ListElement {
                name: "   Z-6. ADD_ZZ_Z"
            }
            ListElement {
                name: "   Z-7. SUB_ZZ_Z"
            }

            ListElement {
                name: "   Z-8. MUL_ZZ_Z"
            }

            ListElement {
                name: "   N-9. DIV_ZZ_Z"
            }

            ListElement {
                name: "   N-10. MOD_ZZ_Z"
            }
            ListElement {
                name: "   Q-1. RED_Q_Q"
            }

            ListElement {
                name: "   Q-2. INT_Q_B"
            }

            ListElement {
                name: "   Q-3. TRANS_Z_Q"
            }

            ListElement {
                name: "   Q-4. TRANS_Q_Z"
            }
            ListElement {
                name: "   Q-5. ADD_QQ_Q"
            }

            ListElement {
                name: "   Q-6. SUB_QQ_Q"
            }

            ListElement {
                name: "   Q-7. MUL_QQ_Q"
            }

            ListElement {
                name: "   Q-8. DIV_QQ_Q"
            }
            ListElement {
                name: "   P-1. ADD_PP_P"
            }

            ListElement {
                name: "   P-2. SUB_PP_P"
            }

            ListElement {
                name: "   P-3. MUL_PQ_P"
            }

            ListElement {
                name: "   P-4. MUL_Pxk_P"
            }
            ListElement {
                name: "   P-5. LED_P_Q"
            }

            ListElement {
                name: "   P-6. DEG_P_N"
            }

            ListElement {
                name: "   P-7. FAC_P_Q"
            }

            ListElement {
                name: "   P-8. MUL_PP_P"
            }
            ListElement {
                name: "   P-9. DIV_PP_P"
            }

            ListElement {
                name: "   P-10. MOD_PP_P"
            }

            ListElement {
                name: "   P-11. GCF_PP_P"
            }

            ListElement {
                name: "   P-12. DER_P_P"
            }
            ListElement {
                name: "   P-13. NMR_P_P"
            }
        }
    }

    Image {
        id: image
        x: 274
        y: 67
        width: 350
        height: 346
      //  source: "C:/C++/DM-computer-algebra/dm-gui/leti_logo_krug-eng_2019.png"
        source: "../kate/leti_logo_krug-eng_2019.png"
        fillMode: Image.Stretch
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
}

/*##^##
Designer {
    D{i:1;anchors_height:480;anchors_width:640}
}
##^##*/
