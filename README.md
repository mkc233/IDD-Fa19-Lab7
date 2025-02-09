# Video Doorbell, Lab 7

*A lab report by Michael Chan*

### In This Report

1. Upload a video of your version of the camera lab to your lab Github repository
1. As usual, update your class Hub repository to add your [forked IDD-Fa18-Lab7](/FAR-Lab/IDD-Fa18-Lab7) repository.
1. Answer the questions in-line below on your README.md.

## Part A. HelloYou from the Raspberry Pi

**a. Link to a video of your HelloYou sketch running.**

[HelloYou](https://youtu.be/XgwcEyXctdU)

## Part B. Web Camera

**a. Compare `helloYou/server.js` and `IDD-Fa18-Lab7/pictureServer.js`. What elements had to be added or changed to enable the web camera? (Hint: It might be good to know that there is a UNIX command called `diff` that compares files.)**

The variable NodeWebcam = require ("node-webcam") is added in order to load the webcam module.  
The variable opts helps define how the webcam is operated by specifcing the size of the picture, the quality, how long to delay after pushing the take picture button before the camera actually takes a picture. 
There is the Webcam = NodeWebcam.create(opts); to start the webcam.
The socket.on('takePicture', function() is added to prompt the camera to take a picture when the button is pressed on the website.  Adn their is also a final function which captures and stores the pictures.  

**b. Include a video of your working video doorbell**

[Video Doorbell](https://youtu.be/Fq2nImVmxTQ)

The below code was added under the parser to take pictures when the button is pressed.
```
serial.pipe(parser);
parser.on('data', function(data) {
  console.log('Data:', data);
  io.emit('server-msg', data);
  switch (data){
    case "light":
      var imageName = new Date().toString().replace(/[&\/\\#,+()$~%.'":*?<>{}\s-]/g, '');
      console.log('making a making a picture at'+ imageName);
      NodeWebcam.capture('public/'+imageName, opts, function( err, data ) {
      io.emit('newPicture',(imageName+'.jpg'));
  });
    break;
}
```

## Part C. Make it your own

**a. Find, install, and try out a node-based library and try to incorporate into your lab. Document your successes and failures (totally okay!) for your writeup. This will help others in class figure out cool new tools and capabilities.**

[Nyancat](https://youtu.be/HWAwThVGedk)

**b. Upload a video of your working modified project**

I updated the code to allow for two images to be taken either by pressing the buttons the breadboard or pushing the buttons on the website.  The two images can then be compared by the user.  

[Picture Comparison](https://youtu.be/vOtLAS--wZ0)
