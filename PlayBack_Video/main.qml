import QtQuick 2.4
import QtQuick.Window 2.4
//import QtMultimedia 5.15
import VideoOperations 1.0

    Window{
    id:parntWindow
    width: 640
    height: 60
    visible: true
    title: qsTr("Video Player")
    flags: Qt.WindowMinimized
    BackGroundWdgt{
    id:bkGndWdgt
    windowActivate: parntWindow
    file_Name: "Default"

    }
     //onColorChanged:{}
        Rectangle{
            id:filebtn
             //   Text: qsTr("Select a File")
            width:100
            height:50
            border.color: "Black"
            color: "Blue"
            border.width: 2

            Image{id:img
                source:"Folder-Icon.png"

                x:20
                y:5
                width:50
                height:40
               // anchors.verticalCenter: filebtn.verticalCenter
                horizontalAlignment: Image.AlignHCenter
                       verticalAlignment: Image.AlignVCenter
            }
            property bool pressed: mouse.pressed
            onPressedChanged: {
                bkGndWdgt.open()

               // bkGndWdgt.fileSelectionDialog()
            }
            MouseArea {
                   id: mouse
                   anchors.fill: parent
                   onClicked:filebtn.pressed//PlayVideoCls.fileSelectionDialog()
            }
        }
        Rectangle{
            id:playbtn
             //   Text: qsTr("Select a File")
            x:100
            width:100
            height:50
            border.color: "Black"
            color: "Blue"
            border.width: 2
            Image{id:imgplay
                source:"play.png"

                x:20
                y:5
                width:50
                height:40
               // anchors.verticalCenter: filebtn.verticalCenter
                horizontalAlignment: Image.AlignHCenter
                       verticalAlignment: Image.AlignVCenter
            }
             property bool pressed: playMouse.pressed
            onPressedChanged: {  bkGndWdgt.onPlayPressed()
            sliderctrl.x=bkGndWdgt.onProgressSlider()
            }
            MouseArea {
                   id: playMouse
                   anchors.fill: parent
                   onClicked:playbtn.pressed//PlayVideoCls.fileSelectionDialog()
            }
         /*   PropertyAnimation
            {target: sliderctrl
                property: "value"
                from: 0
                to: 1
                duration: 1000
                running: true
                loops: Animation.Infinite
            }*/
        }
        Rectangle{
            id:pausebtn
             //   Text: qsTr("Select a File")
            x:200
            width:100
            height:50
            border.color: "Black"
            color: "Blue"
            border.width: 2
            Image{id:imgpause
                source:"pause.png"

                x:20
                y:5
                width:50
                height:40
               // anchors.verticalCenter: filebtn.verticalCenter
                horizontalAlignment: Image.AlignHCenter
                       verticalAlignment: Image.AlignVCenter
            }
             property bool pressed: pauseMouse.pressed
            onPressedChanged: {  bkGndWdgt.onPausePressed()
            }
            MouseArea {
                   id: pauseMouse
                   anchors.fill: parent
                   onClicked:pausebtn.pressed//PlayVideoCls.fileSelectionDialog()
            }
        }

        Rectangle
        {
            id:progrsbar
            x:300
            width:300
            height:50
            border.color: "Black"
            color: "Blue"
            border.width: 2
        Rectangle{
            id:sliderctrl
             //   Text: qsTr("Select a File")
            x:0
            width:20
            height:50
            border.color: "Black"
            color: "Blue"
            border.width: 2

            Image{id:imgsliderbtn
                source:"slider-btn.jpg"


                width:20
                height:50
                fillMode:Image.Pad

            }
             //property bool pressed: slidermouse.pressed
            //onPressedChanged: {  bkGndWdgt.onPausePressed()}

        }
       /* property bool xChanged:true
        onXChanged:{
            sliderctrl.xChanged()
            bkGndWdgt.onSliderDragged(sliderctrl.x)}*/

            MouseArea {
                   id: slidermouse
                   anchors.fill: progrsbar


                       drag{ target:sliderctrl
                       axis:Drag.XAxis
                       minimumX:0
                       maximumX: 300
                        minimumY: 0
                        maximumY: 0
                   }
                  //
                   //onClicked:sliderctrl.pressed//PlayVideoCls.fileSelectionDialog()
                    onPositionChanged: {
                        //if(drag.active)
                        bkGndWdgt.onSliderDragged(mouseX)}//{ //if(drag.active)sliderctrl.x=mouseX


            }

        }

}

