#pragma once

class Result:public Scene {

public:
    static Result* instance() { return &instance_; }
    
    void init();
    void deinit();
    void update();
    void render();

private:
    static Result instance_;
};