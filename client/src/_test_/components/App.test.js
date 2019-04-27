import React from 'react';
import ReactDOM from 'react-dom';
import App from '../../components/App';
import {shallow} from 'enzyme'
import {Provider} from 'react-redux'
import configureStore from 'redux-mock-store'
import initialState from "../../initialState"
import { configure } from 'enzyme';
import Adapter from 'enzyme-adapter-react-16';

configure({ adapter: new Adapter() });
describe('App test',()=>{
  const mockStore = configureStore();
  let store, container;

  beforeEach(()=>{
    store = mockStore(initialState);
    container = shallow(<Provider store={store}><App /></Provider>)
  });

  it('renders without crashing', () => {
  const div = document.createElement('div');
  ReactDOM.render(container, div);
  ReactDOM.unmountComponentAtNode(div);
  });
})