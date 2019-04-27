import React from 'react';
import ReactDOM from 'react-dom';
import LoginPanel from '../../components/LoginPanel';
import {shallow} from 'enzyme'
import {Provider} from 'react-redux'
import configureStore from 'redux-mock-store'
import initialState from "../../initialState"
import { configure } from 'enzyme';
import Adapter from 'enzyme-adapter-react-16';


configure({ adapter: new Adapter() });
describe('LoginPanel test',()=>{
  const mockStore = configureStore();
  let store, container;

  beforeEach(()=>{
    store = mockStore(initialState);
    container = shallow(<Provider store={store}><LoginPanel /></Provider>)
  });

  it('Renders LoginPanel',()=>{
      expect(container).toBeTruthy()
  })
})