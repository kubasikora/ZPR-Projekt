const initialState = {
    auth: {
        login: null,
        password: null,
    },
    data: {
        loading: true,
        data: [],
    },
    processState: {
        devices: [
            {
                deviceName: "CS7",
                deviceLabel: "Temperatura gazu",
                deviceSerial: "b31edaf2-4fb7-11e9-8647-d663bd873d93",
                deviceValue: "0.00",
                deviceUnit: "°C",
                deviceId: "1"
            },
            {
                deviceName: "FLOMID XT5/XT5H",
                deviceLabel: "Przepływ gazu",
                deviceSerial: "99e6c2cb-68a3-4f27-a289-5be85ce96669",
                deviceValue: "0",
                deviceUnit: "l/h",
                deviceId: "2"
            },
            {
                deviceName: "ADZ-SML-10.0",
                deviceLabel: "Ciśnienie w rurociągu",
                deviceSerial: "d2fd535c-7ebd-4a29-b59e-702b9cb9617f",
                deviceValue: "0.00",
                deviceUnit: "bar",
                deviceId: "3"
            },
            {
                deviceName: "AM2302",
                deviceLabel: "Wilgotność gazu",
                deviceSerial: "d5397e20-43f9-457a-b582-3e9a64d56fed",
                deviceValue: "0",
                deviceUnit: "%",
                deviceId: "4"
            }
        ]
    }
}

export default initialState;