#include "TransformationRegistry.h"
#include "Transformation.h"
#include "Pipeline.h"
#include "Task1/PostgresFactory.h"
#include "RunCheckpoint.h"
#include "CheckpointManager.h"

int main() {
    // 1) Registry + prototype registration
    TransformationRegistry* registry = new TransformationRegistry();
    registry->registerStep("dedup", new DeduplicateStep("dedup"));
    registry->registerStep("aggregate", new AggregateByRegionStep("aggregate"));

    // 2) Batch pipeline with Postgres factory
    Pipeline* pipeline = new BatchPipeline(new PostgresFactory());

    // 3) Add cloned steps from registry
    pipeline->addStep(registry->create("dedup"));
    pipeline->addStep(registry->create("aggregate"));

    // 4) Create checkpoint manager
    CheckpointManager* manager = new CheckpointManager();

    // 5) Run, checkpoint, save
    pipeline->run();
    RunCheckpoint* cp = pipeline->createCheckpoint();
    manager->save(cp);

    // 6) Clean up owned memory
    delete manager;
    delete pipeline;
    delete registry;

    return 0;
}
