export default abstract class Engine {

    protected g: iZephyrus | null = null;     // core engine wasm
    protected canvasId: string;
    protected width: number;
    protected height: number;

    protected constructor(canvasId: string, w = 480, h = 640) {
        this.canvasId = canvasId;
        this.width = w;
        this.height = h;
    }

    abstract onCreate(): boolean;

    private async init() {
        this.g = (await Zephyrus()) as iZephyrus;
        this.g.main(this.canvasId, this.width, this.height);
    }

    public async start(): Promise<boolean> {
        await this.init();
        this.onCreate();
        return Promise.resolve(true);
    }
}
