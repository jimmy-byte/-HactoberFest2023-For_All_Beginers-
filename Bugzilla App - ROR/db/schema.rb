# This file is auto-generated from the current state of the database. Instead
# of editing this file, please use the migrations feature of Active Record to
# incrementally modify your database, and then regenerate this schema definition.
#
# This file is the source Rails uses to define your schema when running `rails
# db:schema:load`. When creating a new database, `rails db:schema:load` tends to
# be faster and is potentially less error prone than running all of your
# migrations from scratch. Old migrations may fail to apply correctly if those
# migrations use external dependencies or application code.
#
# It's strongly recommended that you check this file into your version control system.

ActiveRecord::Schema.define(version: 2021_06_25_100823) do

  create_table "assigns", force: :cascade do |t|
    t.string "assigned_to"
    t.integer "bug_id", null: false
    t.datetime "created_at", precision: 6, null: false
    t.datetime "updated_at", precision: 6, null: false
    t.index ["bug_id"], name: "index_assigns_on_bug_id"
  end

  create_table "bugs", force: :cascade do |t|
    t.string "title"
    t.text "description"
    t.string "priority"
    t.integer "days_to_complete"
    t.string "status"
    t.integer "user_id", null: false
    t.datetime "created_at", precision: 6, null: false
    t.datetime "updated_at", precision: 6, null: false
    t.integer "created_by"
    t.string "assigned_to"
    t.text "comment"
    t.index ["user_id", "created_at"], name: "index_bugs_on_user_id_and_created_at"
    t.index ["user_id"], name: "index_bugs_on_user_id"
  end

  create_table "users", force: :cascade do |t|
    t.string "name"
    t.string "email"
    t.datetime "created_at", precision: 6, null: false
    t.datetime "updated_at", precision: 6, null: false
    t.string "password_digest"
    t.integer "role"
    t.string "activation_digest"
    t.boolean "activated", default: false
    t.boolean "admin", default: false
    t.index ["email"], name: "index_users_on_email", unique: true
  end

  add_foreign_key "assigns", "bugs"
  add_foreign_key "bugs", "users"
end
