// 2667
type helloWorldFunc = () => () => string;

const createHelloWorld_ts : helloWorldFunc = () => {
    return () => {
        return 'Hello World'
    };
};
