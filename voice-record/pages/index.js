import React, { Component } from 'react';



class Index extends Component {
  state = {
    active: false,
    mediaRecorder: null,
    audioChunks: [],
    audioBlob: null,
    audioURLs: [],

  };

  componentDidMount() {
    this.prepareRecording();
  }

  prepareRecording = () => {
    this.setState({ audioChunks: [] });

    navigator.mediaDevices
      .getUserMedia({ audio: true })
      .then((stream) => {
        let mediaRecorder = new MediaRecorder(stream, { type: 'audio/wav' });
        this.setState({ mediaRecorder: mediaRecorder });
      })
      .catch((error) => {
        console.error('Error accessing microphone:', error);
      });
  };

  startRecording = () => {
    if (this.state.mediaRecorder) {
      this.setState({ audioChunks: [] });
      this.state.mediaRecorder.start();
      this.setState({ active: true });
      this.state.mediaRecorder.addEventListener('dataavailable', (e) => {
        this.state.audioChunks.push(e.data);
      });
    }
  };

  stopRecording = () => {
    this.setState({ audioChunks: [] });

    if (this.state.mediaRecorder) {
      this.state.mediaRecorder.stop();
      this.state.mediaRecorder.addEventListener('stop', () => {
        let audioBlob = new Blob(this.state.audioChunks, { type: 'audio/wav' });
        let audioURL = URL.createObjectURL(audioBlob);

        // Update the audioURLs array with the new audioURL
        this.setState((prevState) => ({
          audioURLs: [...prevState.audioURLs, audioURL],
          audioBlob: audioBlob,
          active: false,
        }));
      });
    }
  };


  render() {
  
    return (
      <div className="container bg-slate-800 h-screen mx-auto p-8">
        <h1 className="text-2xl font-bold mb-4">Audio Recorder</h1>
        <div id="recording-controls" className="flex justify-center">
          {!this.state.active ? (
            <>
              <div
                id="recordButton"
                className="record-button h-10 cursor-pointer w-10 bg-red-500 rounded-full"
                onClick={this.startRecording}
              ></div>
              <span className="font-bold text-xl m-1.5">Start Recording</span>
            </>
          ) : (
            <>
              <div
                id="recordButton"
                className="record-button h-10 cursor-pointer w-10 bg-black rounded-md"
                onClick={this.stopRecording}
              ></div>
              <span className="font-bold text-xl m-1.5">Stop Recording</span>
            </>
          )}
        </div>
        {this.state.audioURLs.map((audioURL, index) => (
          <div className='m-2' key={index}>
            <audio src={audioURL} controls />
          </div>
        ))}
      </div>
    );
  }
}

export default Index;
