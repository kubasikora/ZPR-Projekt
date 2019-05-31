
import React from "react";
import { Line } from 'react-chartjs-2';
import "./Graphs.css"
class GraphsView extends React.Component {
  constructor(props) {
    super(props);
  }

  setLabels(){
   //let labels = this.props.data.forEach(device=>{return device.data.forEach(element => {return element.timestamp})});
   return this.props.data[0].data.map(element=>{return element.timestamp});   
  }
  setDatasets(){
    return(this.props.data.map(device=>{
      let label = device.deviceId;
      let color1 ="rgba("+this.props.colors[device.deviceId-1]+",1)";
      let color04="rgba("+this.props.colors[device.deviceId-1]+",0.4)";
      let data = device.data.map(element=>{return element.value})
      return {label,
              fill:false,
              lineTension: 0.1,
              backgroundColor: color04,
              borderColor: color1,
              borderCapStyle: 'butt',
              borderDash: [],
              borderDashOffset: 0.0,
              borderJoinStyle: 'miter',
              pointBorderColor: color1,
              pointBackgroundColor: '#fff',
              pointBorderWidth: 1,
              pointHoverRadius: 5,
              pointHoverBackgroundColor: color1,
              pointHoverBorderColor: 'rgba(220,220,220,1)',
              pointHoverBorderWidth: 2,
              pointRadius: 1,
              pointHitRadius: 10,
              data
              }
    }))
  }
 
  render() {
    console.log(this.setDatasets())
    const data = {
      labels: this.setLabels(),
      datasets:  this.setDatasets(),
    };
    return (
      <div className= "chart-frame">
      <Line ref="chart" data={data} style={{width: "490px",height:"950px"}}/>
      </div>    );
  }
}


export default GraphsView;