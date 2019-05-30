
import React from "react";
import { Line } from 'react-chartjs-2';
import "./Graphs.css"
class GraphsView extends React.Component {
  constructor(props) {
    super(props);
  }

  setLabels(){
   //let labels = this.props.data.forEach(device=>{return device.data.forEach(element => {return element.timestamp})});
   //let labels = this.props.data.forEach(device=>{return device.data.map(element=>{return element.timestamp})})
   //console.log('props',labels)
   //return new Set(labels)
  }
 
  render() {console.log(this.setLabels())
    const data = {
      labels: ['January', 'February', 'March', 'April', 'May', 'June', 'July'],
      datasets: [
        {
          label: 'My First dataset',
          fill: false,
          lineTension: 0.1,
          backgroundColor: 'rgba(75,192,192,0.4)',
          borderColor: 'rgba(75,192,192,1)',
          borderCapStyle: 'butt',
          borderDash: [],
          borderDashOffset: 0.0,
          borderJoinStyle: 'miter',
          pointBorderColor: 'rgba(75,192,192,1)',
          pointBackgroundColor: '#fff',
          pointBorderWidth: 1,
          pointHoverRadius: 5,
          pointHoverBackgroundColor: 'rgba(75,192,192,1)',
          pointHoverBorderColor: 'rgba(220,220,220,1)',
          pointHoverBorderWidth: 2,
          pointRadius: 1,
          pointHitRadius: 10,
          data: [65, 59, 80, 81, 56, 55, 40]
        }
      ]
    };
    console.log(this.props)
    return (
      <div className= "chart-frame">
      <Line ref="chart" data={data} style={{width: "490px",height:"950px"}}/>
      </div>    );
  }
}


export default GraphsView;